import subprocess
import sys
import os, glob

def deleteOutputFiles():
    for filename in glob.glob("input/out_*"):
        os.remove(filename)

def compareFiles(file1, file2):
    f1 = open(file1, "r")
    out1 = f1.readlines()
    f2 = open(file2, "r")
    out2 = f2.readlines()
    if len(out1) != len(out2):
        return False
    
    for i in range(len(out1)):
        x = out1[i].replace("\n", "").strip()
        y = out2[i].replace("\n", "").strip()
    v1 = [int(a) for a in x.split()]
    v1.sort()
    v2 = [int(a) for a in y.split()]
    v2.sort()
    if v1 == v2:
        return True
    return False

if __name__ == "__main__":
    try:
        command = "quicktest output --tout=4000 --ml=10000000 -t " +  str(sys.argv[1]) + " -p input/ --save-out "
        output = subprocess.run(command, stdout = subprocess.PIPE, stderr = subprocess.DEVNULL, shell = True)
        if output.returncode != 0:
            print("Compilation error")
        else:
            out = str(output.stdout, 'utf-8').strip().split('\n')
            for i in range(len(out)):
                x = out[i].strip()
                if "OK" in x:
                    xw = x.split(' ')
                    if os.path.isfile("input/out_" + xw[0] + ".in"):
                        if compareFiles("input/out_" + xw[0] + ".in", "output/" + xw[0] + ".out"):
                            print(x)
                        else:
                            print(xw[0] + " [WA] Wrong answer " + xw[4])
                    else:
                        print(xw[0] + " [RTE] Runtime Error " + xw[4])
                else:
                    print(x)
        deleteOutputFiles()
    except Exception as e:
        deleteOutputFiles()
        print(str(e))
