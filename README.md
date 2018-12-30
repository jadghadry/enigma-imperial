# The Enigma Machine



## 📄 Abstract

The enigma machine is a series of electro-mechanical cipher components prominently used during World War II in order to protect commercial, diplomatic and military communication. It was built on top of three key components, defined below.

#### Plugboard

When a key on the Enigma machine keyboard is pressed, it closes an electrical circuit, and causes a signal to first be sent to the plugboard. The plugboard consists of a series of contacts that can be connected by plugboard cables. The effect of connecting two letters via plugboard cables is to swap the input signals of these letters before sending them to the rotors.

#### Rotors

A rotor is a wheel with the upper-case alphabet (in order) on the rim and a hole for an axle. On both sides of a rotor are 26 contacts each under a letter. Each contact on one side is wired to a contact on the other side at a different position, effectively mapping each letter to a different one.

#### Reflector

The reflector is a device at the end of the rotors which has contacts for each letter of the alphabet on one side only. The letters are wired up in pairs, so that an input current on one letter is output back to a different letter. It causes the input signal to be reflected back through the rotors and plugboard, and then into one of the bulbs on the output board.



## 🏷 Task

You are to implement a general Enigma machine in C++ as a program that is configured through its command line arguments, and then encrypts / decrypts messages passed to it on the standard input stream, printing the result on the standard output stream.

Normally an Enigma machine is physically limited to a fixed number of rotors, and only a small number of rotors with different wirings exist that can be used. **Your program should not have these restrictions**. It should be able to read in details of the rotors, plugboard and reflector wirings from configuration files, whose names are specified on the command line.



## 🖥 Run Project

In order to effectively run the project, configure the plugboard, reflector and rotor files as described in the project spec. Then, if you want to configure an enigma machine using three rotors, a sample plugboard and a reflector, the following arguments should be passed to the `main(int argc, char **argv)` function.

```
./enigma plugboards/I.pb reflectors/I.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos
```

Here the leftmost rotor would use the mapping described in `I.rot`, and the middle and right-hand rotors would use the mapping described in `II.rot` and `III.rot` respectively, with their starting positions specified in `I.pos`. The plugboard would use the mapping described in `I.pb` and the reflector the one in `I.rf`.



## 💡 Acknowledgements

Much of the work in this project is inspired by [@wmarsey](https://github.com/wmarsey).