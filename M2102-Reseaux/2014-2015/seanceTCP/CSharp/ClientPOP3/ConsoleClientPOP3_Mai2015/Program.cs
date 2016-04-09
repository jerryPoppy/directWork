
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net.Sockets;
using System.Net;
using System.IO;


namespace ConsoleClientPOP3_Mai2015
{
    class Program
    {
        static bool VERBOSE = true;
        static string username = "mstinfo1";
        static string password = "master";
        static string nomServeur = "pop.free.fr";

        static void FATAL(string Message)
        {
            Console.WriteLine(Message);
            Console.ReadLine();
            Environment.Exit(-1);
        }


        static void LireLigne(StreamReader input, out string ligne)
        {
            ligne = input.ReadLine();
            if (VERBOSE)
                Console.WriteLine("     recu  >> " + ligne);
        }
        static void EcrireLigne(StreamWriter output, string ligne)
        {
            output.WriteLine(ligne);
            if (VERBOSE)
                Console.WriteLine("     envoi << " + ligne);
        }

        static void travail(TcpClient socketClient)
        {
            // Stream pour lecture et écriture
            StreamWriter sw;
            StreamReader sr;

            if (socketClient.Connected)
            {
                // connexion ok, mise en place des streams pour lecture et écriture
                sr = new StreamReader(socketClient.GetStream(), Encoding.Default);
                sw = new StreamWriter(socketClient.GetStream(), Encoding.Default);
                sw.AutoFlush = true;

                string ligne,tampon;

                /* reception banniere */
                LireLigne(sr, out ligne);  // ou  ligne = sr.ReadLine();
                if(ligne[0] != '+') {
                    FATAL("Pas de banniere. Abandon");
                };

                /* envoi identification */
                tampon="USER "+username;
                EcrireLigne(sw, tampon);   // ou  sw.WriteLine(tampon);
                LireLigne(sr, out ligne);  // ou  ligne = sr.ReadLine();
                if(ligne[0] != '+') {
                    FATAL("USER rejeté. Abandon");
                };

                /* envoi mot de passe */
                tampon="PASS "+password;
                EcrireLigne(sw, tampon);
                LireLigne(sr, out ligne);
                if (ligne[0] != '+') {
                    FATAL("PASS rejeté. Abandon");
                }

                 /* envoi STAT pour recuperer nb messages */
                tampon="STAT";
                EcrireLigne(sw, tampon);

                /* reception de +OK n mm */
                LireLigne(sr, out ligne);
                string[] lesValeurs = ligne.Split(' ');
                int nombre_de_messages = Int32.Parse(lesValeurs[1]);
                int taille_boite = Int32.Parse(lesValeurs[2]);
                Console.Write("Il y a "+nombre_de_messages.ToString()+" messages dans la boite.\n");
                Console.Write("La taille totale est de "+taille_boite.ToString()+" octets.\n");

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

            int port = 110;
  
            socketClient = connexion(nomServeur, port);
            travail(socketClient);
            socketClient.Close();

            Console.WriteLine("Fin du client -> Taper une touche pour terminer");
            Console.ReadLine();
        }
    }
}

        