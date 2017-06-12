import socket

#> Creamos el socket cliente
client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

#> Intentamos establecer la coneccion con el server en el puerto 8888
# cambiar @Param "localhost" por la ip con la que desea conectarse
client.connect(("localhost", 8888))

while True:
    msg = str(input("> "))      # Ingresamos un mensaje
    byte = msg.encode('utf-8')  # codificamos el mensaje en utf-8
    client.send(byte)           # Enviamos el mensaje codificado
    if msg == "quit":
        break

client.close()                  # Cerramos socket cliente