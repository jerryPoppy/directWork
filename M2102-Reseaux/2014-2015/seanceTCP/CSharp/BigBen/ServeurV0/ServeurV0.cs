using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net.Sockets;
using System.Net;

namespace ServeurV0
{
    class ServeurV0
    {
        static Socket InitService(int port)
        {
            Socket socketServeur = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            IPAddress adresse = IPAddress.Parse("127.0.0.1");
            socketServeur.Bind(new IPEndPoint(adresse, port));
            //Console.WriteLine(socketServeur.LocalEndPoint.ToString());
            Console.WriteLine("Le serveur est à l'écoute sur le port " + ((IPEndPoint)socketServeur.LocalEndPoint).Port.ToString());
            socketServeur.Listen(5);
            return (socketServeur);
        }

        static void Travail(Socket socketTravail)
        {
            string HH, MM, SS;
            HH = DateTime.Now.Hour.ToString("D2");
            MM = DateTime.Now.Minute.ToString("D2");
            SS = DateTime.Now.Second.ToString("D2");
            socketTravail.Send(Encoding.ASCII.GetBytes(HH));
            socketTravail.Send(Encoding.ASCII.GetBytes(MM));
            socketTravail.Send(Encoding.ASCII.GetBytes(SS));
            Console.WriteLine("Envoi de " + HH + ':' + MM + ':' + SS);
        }

        static void Main(string[] args)
        {
            int portEcoute = 4321;
            //TcpListener socketConnexion,socketTravail;
            Socket socketConnexion, socketTravail;
            Console.WriteLine("Début Serveur");
            socketConnexion = InitService(portEcoute);
            while (true)
            {
                socketTravail = socketConnexion.Accept();
                Travail(socketTravail);
                socketTravail.Close();
            }
            Console.WriteLine("Fin du serveur => Taper une touche pour terminer");
            Console.ReadLine();
        }
    }
}
