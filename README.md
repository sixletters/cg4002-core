# CG4002 Capstone Project
##### Authors: Harris Maung, Alicia Ho, Kian En, Sarrah


The computer engineering capstone consists of a laser tag game where 2 players an play at any point in time.

## Systems Architecture
![alt text](https://github.com/sixletters/cg4002-core/blob/main/Screenshot%202022-11-13%20at%209.38.38%20PM.png)

## External Communications 
#### dependencies
- Protobuf compiler. To download the protobuf library please follow the information at https://developers.google.com/protocol-buffers/docs/downloads
- Vivado + Vivado HLS 2020.1
- Ultra96 Board + Pynq OS 
- Bluepy
- Numpy
### starting the external communications processes. 
first set up a SSH tunnel with the following commands
```sh
ssh -L [laptopPort]:192.168.95.224:[ultra96Port] [user]@stu.comp.nus.edu.sg]
```
we can then SSH to the sunfire server and go to the project root directory and run the following
```sh
cd ultra96
cmake -S . -B build
cd build
make
./ultra96 [evalServerAddress] [evalServerPort] 
```
The process should then ask for the number of players, which can either be 1 or 2.

## Hardware AI acclerator and Python utility-server.
run this in jupyter notebook to start whole process and communications with ext comms.
The folder structure and usage is as follows:
- final_model is a directory that contains the .bit and .hwh files to be loaded onto the FGPA
-20hz_35buffer_data_eval_2_1 contains the datasets to train the model
- Vivado_source contains the archived Vivado file.
- HLS_source contains source code and all required files for Vivado HLS, can be imported as zip file
- mlp_model.ipynb contains software ai code, including hyperparameter tuning, software testing, and weights & biases
- predict.py contains API calls to predict an action with IMU data.
-SWHW_Impl.ipynb contains testing code for hardware ai to check average time taken for a prediction
-realPredict.ipynb is the wrapper around the pythons APIs and acts as a standalone server that communicates with the core process and game engine.

```sh
ssh [user]@stu.comp.nus.edu.sg]
ssh [xilinx]
jupyter notebook
```
on local machine, open the IP of the xilinx on browser, and run realPredict.ipynb

## Internal communications
#### Installation
```sh
pip install bluepy protobuf struct threading numpy
python relay.py
```
#### folder structure and file
- relay.py contains the process in which communicaitons with external comms happen
- connect.py Contains the connection to the beetles as well as the internal communications processsing
- Util.py contains numpy functions to find the threshold for AI



