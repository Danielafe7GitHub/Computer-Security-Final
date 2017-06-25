#> Es importante desactivar el firewall del servidor, si se quiere hacer una conexion con otra ordenador!!!!!!!!!!!!!!!!!
#> En Ubuntu escribir en la shell "$sudo ufw disable" para desactivar y "$sudo ufw enable" para activar
import socket

class CServer:
    portServer = 8888
    client = None
    address = None
    filePath = ""
    def __init__(self, port = 8888, numBytes = 64):
        self.filePath = "../serverMessage.txt"
        self.portServer = port
        self.initServer(self.portServer)
        try:
            self.listen(numBytes)
        except Exception as e:
            print ("Conecction is done!")
            self.server.close()

    def initServer(self, port):
        #> Creamos el servidor
        self.server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        #self.server.setblocking(0)
        #> Asociamos a un host publico en el puerto 8888
        #NOTA: el cliente y el servidor tienen que establecer conexion por el mismo puerto
        self.server.setsockopt(socket.SOL_SOCKET,socket.SO_REUSEADDR,1)
        self.server.bind(('', port))

        #> listen le dice al servidor que tiene que escuchar 5 veces
        self.server.listen(5)

        #> Aceptamos conexion externa
        (self.client, self.address) = self.server.accept()

    def listen(self, numBytes):
        message = ""
        file = open(self.filePath, "w")
        while True:
            tmp = self.client.recv(numBytes)        # recibimos mensajes de 8 bytes del cliente
            #print ("receiving ... ", tmp)
            msg = tmp.decode('utf-8')   # Decodificamos el mensaje enviado
            message = message + msg
            print(msg)                  # Imprimimos
            file.write(msg+"\n")
            self.client.send(tmp)

        file.close()
        self.server.close()                  # Cerramos el servidor

serverSocket = CServer()