using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net.Sockets;
using System.Net;
using System.IO;

namespace ClientV1
{
    class ClientV1
    {
        static void FATAL(string Message)
        {
            Console.WriteLine(Message);
            Environment.Exit(-1);
        }

        static void travail(TcpClient socketClient)
        {
            String HH, MM, SS;
            // Stream pour lecture et écriture
            StreamWriter sw;
            StreamReader sr;

            if (socketClient.Connected)
            {
                // connexion ok, mise en place des streams pour lecture et écriture
                sr = new StreamReader(socketClient.GetStream(), Encoding.Default);
                sw = new StreamWriter(socketClient.GetStream(), Encoding.Default);
                sw.AutoFlush = true;

                HH = sr.ReadLine(); 
                MM = sr.ReadLine();
                SS = sr.ReadLine();

                Console.Write("Il est " + HH + ":" + MM + ":" + SS);
                Console.WriteLine(" sur le serveur.");
            }
        }

        static TcpClient connexion(string nomServeur, int port)
        {
            TcpClient socketClient = new TcpClient();

            //(AddressFamily.InterNetwork,SocketType.Stream,ProtocolType.Tcp);
            IPAddress adresse = IPAddress.Parse("127.0.0.1");
            //IPAddress adresse;
            bool trouve = false;
            IPAddress[] adresses = Dns.GetHostAddresses(nomServeur);
            foreach (IPAddress ip in adresses)
            {//on cherche la première adresse IPV4
                if (ip.AddressFamily == AddressFamily.InterNetwork)
                {
                    trouve = true;
                    adresse = ip;
                    break;
                }
            }
            if (!trouve)
            {
                FATAL("Echec recherche IP serveur");
            }
            socketClient.Connect(adresse, port);
            return socketClient;
        }
        static void Main(string[] args)
        {
            Console.WriteLine("Démarrage du client");
            TcpClient socketClient;

            int port = 4321;
            string nomServeur = "localhost";// ou "<nom_machine>"
            socketClient = connexion(nomServeur, port);
            travail(socketClient);
            socketClient.Close();
            Console.WriteLine("Fin du client -> Taper une touche pour terminer");
            Console.ReadLine();

        }
    }
}
