import socket

class CClient:
    port = 8888
    address = "localhost"
    client = None
    file = None
    def __init__(self, address, port = 8888):
        #self.file = open("files/negociation.txt","r")
        self.address = address
        self.port = port
        self.initClient(self.address, self.port)

    def initClient(self, address, port):
        #> Creamos el socket cliente
        self.client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

        #> Intentamos establecer la coneccion con el server en el puerto 8888
        # La siguiente linea intenta establecer la conexion con el servidor localhost, es decir con tu mismo ordenador
        # Si se quiere hacer una conexion con otro ordenador -> cambiar @Param "localhost" por la ip con la que desea conectarse
        #client.connect(("192.168.1.107", 8888))
        self.client.connect(("localhost", port))

    def send(self):
        while True:
            msg = str(input("> "))      # Ingresamos un mensaje

            byte = msg.encode('utf-8')  # codificamos el mensaje en utf-8
            print ("sending ... ", byte)
            self.client.send(byte)           # Enviamos el mensaje codificado
            if msg == "quit":
                break

        self.client.close()                  # Cerramos socket cliente

    def readFile(self):
        content = ""
        while True:
            line = self.file.readline()
            if not line:
                break
            content = content + line
        return content

clientSocket = CClient("localhost",8888)
clientSocket.send()