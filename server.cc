//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "server.h"

Define_Module(Server);

void Server::initialize()
{
    // TODO - Generated method body
}

void Server::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
    cGate *arrivalGate=msg->getArrivalGate();
     if(arrivalGate==gate("in1"))
        {
            std::string ciphertext=msg->getFullName();
            int message_size=ciphertext.size();
            std::string key="hello";
            int key_size=key.size();
            //int total_keySize=(message_size-1)-key_size;
            char ch;

            //std::string new_key = key + ciphertext.substr(0,total_keySize);

            char decrypt[message_size];
            for(int i=0; i<(message_size);i++)
            {
                if(i<key_size)
                {
                    int val=((ciphertext[i]-'a')-(key[i]-'a'));
                    val = (val < 0) ? val + 26 : val;
                    ch=(val%26)+'a';
                }
                else {
                    int val=((ciphertext[i]-'a')-(decrypt[i-key_size]-'a'));
                    val = (val < 0) ? val + 26 : val;
                    ch=(val%26)+'a';
                }
                decrypt[i]=ch;
            }
            decrypt[message_size]='\0'; // add null terminator
            cMessage *newmsgs=new cMessage( decrypt);
            send(newmsgs,"out2");

   }
}
