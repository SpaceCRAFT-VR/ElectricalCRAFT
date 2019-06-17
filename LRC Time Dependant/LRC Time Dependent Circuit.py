import numpy as np
import ahkab
from ahkab import ahkab, circuit, time_functions
import pylab as plt

mycircuit = circuit.Circuit(title= "LRC Time Dependent Circuit")

gnd = mycircuit.get_ground_node()

# Writing net list for the circuit
mycircuit.add_resistor("R1", n1="n1", n2="n2", value=600)
mycircuit.add_inductor("L1", n1="n2", n2="n3", value=15.24e-3)
mycircuit.add_capacitor("C1", n1="n3", n2=gnd, value=119.37e-9)
mycircuit.add_inductor("L2", n1="n3", n2="n4", value=61.86e-3)
mycircuit.add_capacitor("C2", n1="n4", n2=gnd, value=155.12e-9)
mycircuit.add_resistor("R2", n1="n4", n2=gnd, value=1.2e3)

# Defining the voltage square wave function ( all times are in seconds)
# v1 = square wave low value
# v2 = square wave high value
# td = delay time to the first ramp
# tr = rise time from v1 to v2
# pw = pulse width
# tf = fall time from v2 to v1
# per = periodicity interval
voltage_step = time_functions.pulse(v1=0, v2=1, td=500e-9, tr=1e-12, pw=1, tf=1e-12, per=2)
mycircuit.add_vsource("V1", n1="n1", n2=gnd, dc_value=5, ac_value=1, function=voltage_step)

print(mycircuit)

ac_analysis = ahkab.new_ac(start=1e3, stop=1e5, points=100)

r = ahkab.run(mycircuit, ac_analysis)
print('------------------------------------------------------------------------')
print(r)
print('------------------------------------------------------------------------')
print(r['ac'])
print(r['ac'].keys())
print('----------------------------------------------------------------------------')
print(np.abs(r['ac']['Vn4']))


fig = plt.figure()
plt.subplot(211)
plt.semilogx(r['ac']['f'], np.abs(r['ac']['Vn4']), 'o-')
plt.ylabel('abs(V(n4)) [V]')
plt.title(mycircuit.title + " - AC Simulation")

plt.subplot(212)
plt.grid(True)
plt.semilogx(r['ac']['f'], np.angle(r['ac']['Vn4']), 'o-')
plt.xlabel('Angular frequency [rad/s]')
plt.ylabel('arg(V(n4)) [rad]')
fig.savefig('ac_plot.png')
plt.show()
