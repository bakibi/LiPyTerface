gcc `pkg-config --cflags gtk+-3.0` -o out main.c `pkg-config --libs gtk+-3.0`
./out
rm out
