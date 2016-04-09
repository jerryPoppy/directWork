using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net.Sockets;
using System.Net;

namespace ClientV0
{

    class Program
    {
        static void FATAL(string Message)
        {
            Console.WriteLine(Message);
            Environment.Exit(-1);
        }

        static void travail(Socket socketClient)
        {
            Byte[] HH = new Byte[2];
            Byte[] MM = new Byte[2];
            Byte[] SS = new Byte[2];
            socketClient.Receive(HH);
            socketClient.Receive(MM);
            socketClient.Receive(SS);
            Console.Write("Il est " + ASCIIEncoding.ASCII.GetString(HH) + ":" + ASCIIEncoding.ASCII.GetString(MM) + ":" + ASCIIEncoding.ASCII.GetString(SS));
            Console.WriteLine(" sur le serveur.");
        }

        static Socket connexion(string nomServeur, int port)
        {
            Socket socketClient = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            //IPAddress adresse = IPAddress.Parse("127.0.0.1");
            IPAddress adresse=null;
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
            Socket socketClient;
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
