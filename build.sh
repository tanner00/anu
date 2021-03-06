BASE=~/Desktop/anu/

cd "$BASE"

if [ ! -d "obuild" ]
then
    mkdir obuild
fi

for i in *.*; do
    [ -f "$i" ] || break
    
    without_extension="${i%%.*}"
    if [[ "$i" == *.S ]]
    then
	nasm -felf32 "$i" -o "$BASE/obuild/$without_extension.o"
    elif [[ "$i" == *.c ]]
    then
        ~/Desktop/i686-elf-4.9.1-Linux-x86_64/bin/i686-elf-gcc -D"$1" -g -c "$i" -o "$BASE/obuild/"$without_extension".o" -I"$BASE/include" -std=gnu99 -ffreestanding -O0 -Wall -Wextra
    fi
done

~/Desktop/i686-elf-4.9.1-Linux-x86_64/bin/i686-elf-gcc -T "$BASE/link.ld" -g -o "$BASE/obuild/os.bin" -ffreestanding -O0 -nostdlib "$BASE/obuild/"*.o -lgcc
qemu-system-i386 -serial stdio -kernel "$BASE/obuild/os.bin" -display "$2" -m "$3" # dumb gtk output (sdl doesn't work with qemu monitor)
