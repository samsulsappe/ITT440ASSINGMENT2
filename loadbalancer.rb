require "socket"

loadbalancer=TCPServer.open("192.168.235.129",2000)

while true 
client=loadbalancer.accept

rhost=client.peeraddr.last
puts "#{rhost} connect to loadbalancer"

fromclient=client.gets
puts "message from client : #{fromclient}"

if fromclient=="book"
sockettoserver1=TCPSocket.open("192.168.120.128",3000)
sockettoserver1.write(fromclient)
sockettoserver1.close 

elseif fromclient=="pen"
sockettoserver2=TCPSocket.open("192.168.120.129",4000)
sockettoserver2.write(fromclient)
sockettoserver2.close 

else
puts "ERROR!!"

end
end