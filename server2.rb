require "socket"

while true
server=TCPServer.open("192.168.120.129",3000)
loadbalancer.server.accept
puts loadbalancer.gets
loadbalancer.close
server.close
end