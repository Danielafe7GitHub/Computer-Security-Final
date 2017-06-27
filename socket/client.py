import socket
from time import sleep

class CClient:
    port = 8888
    filePath = ""
    client = None
    file = None
    def __init__(self, address, port = 8888):
        print ("Iniciando cliente! ")
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
        print ("conectando a: ", self.address," en progreso ...")
        self.client.connect((self.address, port))
        print ("conectado a: ", self.address, " ! 3:)")
        #self.client.setblocking(0)

    def send(self, filep):
       	self.filePath = filep
       	tmp = open(self.filePath).read()
       	data = tmp.encode('utf-8')
        print ("enviando a ", self.address, " : ", tmp)
       	self.client.sendall(data)
       	self.client.close()
        print ("cerrando conexion cliente!")

    def send2(self, file):
        self.filePath = file
        msg = self.readFile(self.filePath)
        print (msg)
        for i in range(len(msg)):
            piece = msg[i]
            if ( i != len(msg)-1):
                piece = self.removeTrash(piece)
            byte = piece.encode('utf-8')   # codificamos el mensaje en utf-8
            print (piece)
            sleep(0.0005)
            #print ("sending ...", piece, byte)
            self.client.send(byte)  # Enviamos el mensaje codificado
        self.client.close()                  # Cerramos socket cliente

    def readFile(self, file):
        with open(file, "r") as file:  # open the file
            contents = file.readlines()  # put the lines to a variable (list).
        return (contents)

    def removeTrash(self, str):
        return str[:-1]

address = input("ingrese ip a conectar: ")
clientSocket = CClient(str(address), 8888)
clientSocket.send("documento.txt")
