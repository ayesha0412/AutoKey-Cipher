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

network Network
{
    @display("bgb=472,263");
    submodules:
        pc1: Client {
            @display("p=62,75");
        }
        pc2: Client {
            @display("p=347,75");
        }
        server: Server {
            @display("p=215,193");
        }
         connections:
        pc1.out --> server.in1;
        pc2.out --> server.in2;
        server.out1 --> pc1.in;
        server.out2 --> pc2.in;
}
