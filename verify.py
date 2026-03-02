import numpy as np

A = np.loadtxt(r"C:\Users\alexa\source\repos\OPV_lab_1\OPV_lab_1\matrix_A.txt")
B = np.loadtxt(r"C:\Users\alexa\source\repos\OPV_lab_1\OPV_lab_1\matrix_B.txt")
C_cpp = np.loadtxt(r"C:\Users\alexa\source\repos\OPV_lab_1\OPV_lab_1\matrix_C.txt")

C_ref = A @ B

if np.allclose(C_cpp, C_ref):
    print("Корректно")
else:
    print("Не корректно")