#> Es importante desactivar el firewall del servidor, si se quiere hacer una conexion con otra ordenador!!!!!!!!!!!!!!!!!
#> En Ubuntu escribir en la shell "$sudo ufw disable" para desactivar y "$sudo ufw enable" para activar
import socket

class CServer:
    portServer = 8888
    client = None
    address = None
    def __init__(self, port = 8888):
        self.portServer= port
        self.initServer(self.portServer)
        #self.listen()

    def initServer(self, port):
        #> Creamos el servidor
        server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

        #> Asociamos a un host publico en el puerto 8888
        #NOTA: el cliente y el servidor tienen que establecer conexion por el mismo puerto
        server.setsockopt(socket.SOL_SOCKET,socket.SO_REUSEADDR,1)
        server.bind(('', port))


        #> listen le dice al servidor que tiene que escuchar 5 veces
        server.listen(5)

        #> Aceptamos conexion externa
        (self.client, self.address) = server.accept()

    def listen(self, numBytes):
        while True:
            tmp = self.client.recv(numBytes)        # recibimos mensajes de 8 bytes del cliente
            #print ("receiving ... ", tmp)
            msg = tmp.decode('utf-8')   # Decodificamos el mensaje enviado
            if msg == "quit":
                break
            print(msg)                  # Imprimimos
            self.client.send(tmp)

        self.server.close()                  # Cerramos el servidor


serverSocket = CServer()
serverSocket.listen(8)