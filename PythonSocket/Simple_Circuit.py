import ahkab
import socket
import sys
# from ahkab import dc_guess
#ahkab --help

# Create a TCP/IP socket
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Connect the socket to the port where the server is listening
server_address = ('localhost', 1234)
s.connect(server_address)

mycir = ahkab.Circuit('Simple Circuit')


mycir.add_resistor('R1', 'n1', mycir.gnd, value=5)
mycir.add_vsource('V1', 'n2', 'n1', dc_value=8)
mycir.add_resistor('R2', 'n2', mycir.gnd, value=2)
mycir.add_vsource('V2', 'n3', 'n2', dc_value=4)
mycir.add_resistor('R3', 'n3', mycir.gnd, value=4)
mycir.add_resistor('R4', 'n001', 'n3', value=1)
mycir.add_vsource('V3', 'n4', mycir.gnd, dc_value=10)
mycir.add_resistor('R5', 'n2', 'n4', value=4)
mycir.add_resistor('R6','n4','n001',value=10)

opa = ahkab.new_op() # Assembles an OP analysis and returns the analysis object.
r = ahkab.run(mycir, opa)['op']
#print(r)

# print('---------------------------------------------')
# a = mycir.get_nodes_number()
# print(a)
# print('----------------------------------------------')

#print the output to a file
with open('test_file.txt', 'w') as f:
    print(r, file=f)
#
# #read the voltages from the file
# voltage_list ={}
# o = open('test_file.txt','r')
# o1 = o.readlines()
# for x in o1:
#     print(x[20:30])
#
