require "socket"
client=TCPSocket.open("192.168.235.129",2000)

puts "Enter your message : "
message=gets.chomp

rhost=client.peeraddr.last
put "#{rhost}"
client.write(message)
client.close