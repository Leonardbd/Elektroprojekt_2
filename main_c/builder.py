import glob, os
import platform
import subprocess

def get_devices():
    proc = subprocess.Popen(["sh", 'devices.sh'], stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
    output, errors = proc.communicate()
    proc.wait()
    # print(output)
    # print(errors)

    devices = output.strip().split(' ')
    for i, d in enumerate(devices):
        print(f'({i}) {d}')

    # fix later...
    option = int(input("Select: "))
    return devices[option]

def build():
    if platform.system() != 'Darwin':
        print("Only MacOS is currently supported.")
        return 1

    files = []
    os.chdir("./")
    for file in glob.glob("*.c"):
        files.append(file)

    if len(files) == 0:
        print('Can\'t find any .c files')
        return 1

    print('Select file to build')
    for i, f in enumerate(files):
        print(f'({i}) {f}')
    
    # fix later...
    option = int(input("Select: "))
    

    cmd = f'avr-gcc -mmcu=atmega328p -O3 -o output.o {files[option]} && avr-objcopy -O ihex -R .eeprom output.o output.hex'
    print(f"Running: {cmd}")
    status = os.system(cmd)
    
    if(status != 0):
        print("Build failed!")
        return 1

    device = get_devices()

    cmd = f'avrdude -v -patmega328p -carduino -b115200 -P {device} -D -Uflash:w:output.hex'
    print(f"Running: {cmd}")
    status = os.system(cmd)
    
    if(status != 0):
        print("Upload failed!")
        return 1

    cmd = f'rm output.hex output.o'
    print(f"Running: {cmd}")
    status = os.system(cmd)
    
    return status

if __name__ == '__main__':
    build()