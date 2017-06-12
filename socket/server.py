#> Es importante desactivar el firewall del servidor, si se quiere hacer una conexion con otra ordenador!!!!!!!!!!!!!!!!!
#> En Ubuntu escribir en la shell "$sudo ufw disable" para desactivar y "$sudo ufw enable" para activar

import socket
#> Creamos el servidor
server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

#> Asociamos a un host publico en el puerto 8888
#NOTA: el cliente y el servidor tienen que establecer conexion por el mismo puerto
server.setsockopt(socket.SOL_SOCKET,socket.SO_REUSEADDR,1)
server.bind(('', 8888))

#> listen le dice al servidor que tiene que escuchar 5 veces
server.listen(5)

#> Aceptamos conexion externa
(client, address) = server.accept()
while True:
    tmp = client.recv(8)        # recibimos mensajes de 8 bytes del cliente
    msg = tmp.decode('utf-8')   # Decodificamos el mensaje enviado
    if msg == "quit":
        break
    print(msg)                  # Imprimimos
    client.send(tmp)

server.close()                  # Cerramos el servidor
