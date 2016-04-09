using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net.Sockets;
using System.Net;
using System.IO;

namespace ServeurV1
{
    class Serveur1
    {
        static TcpListener InitService(int port)
        {
            IPAddress adresse = IPAddress.Parse("127.0.0.1");
            TcpListener socketServeur = new TcpListener(adresse,port);
            socketServeur.Start();
            Console.WriteLine("Le serveur est à l'écoute sur le port " + port.ToString());
            return (socketServeur);
        }

        static void Travail(TcpClient socketTravail)
        {
            StreamReader sr = new StreamReader(socketTravail.GetStream(), Encoding.Default);
            StreamWriter sw = new StreamWriter(socketTravail.GetStream(), Encoding.Default);
            sw.AutoFlush = true;

            string HH, MM, SS;
            HH = DateTime.Now.Hour.ToString("D2");
            MM = DateTime.Now.Minute.ToString("D2");
            SS = DateTime.Now.Second.ToString("D2");
            sw.WriteLine(HH);
            sw.WriteLine(MM);
            sw.WriteLine(SS);
            Console.WriteLine("Envoi de " + HH + ':' + MM + ':' + SS);
        }

        static void Main(string[] args)
        {
            int portEcoute = 4321;
            TcpListener socketConnexion;
            TcpClient socketTravail;
            Console.WriteLine("Début Serveur");
            socketConnexion = InitService(portEcoute);
            while (true)
            {
                socketTravail = (TcpClient) socketConnexion.AcceptTcpClient();
                Travail(socketTravail);
                socketTravail.Close();
            }
            Console.WriteLine("Fin du serveur => Taper une touche pour terminer");
            Console.ReadLine();
        }
    }
}
