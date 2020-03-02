import random

f = open('gallery', 'w')
for i in range(50, 551, 3):
    spikes = [random.randint(0, 100) for i in range(5)]
    blips = [random.randint(0, 8) for i in range(3)]
    f.write("line\n")
    f.write(f"75 {i} 0 100 {i} {blips[1]}\n")
    f.write("line\n")
    f.write(f"100 {i} {blips[1]} 125 {i} {blips[0]}\n")
    f.write("line\n")
    f.write(f"125 {i} {blips[0]} 150 {i} {blips[2]}\n")
    f.write("line\n")
    f.write(f"150 {i} {blips[2]} 200 {i} {spikes[1]}\n")
    f.write("line\n")
    f.write(f"200 {i} {spikes[1]} 250 {i} {spikes[2]}\n")
    f.write("line\n")
    f.write(f"250 {i} {spikes[2]} 300 {i} {spikes[0]}\n")
    f.write("line\n")
    f.write(f"300 {i} {spikes[0]} 350 {i} {blips[0]}\n")
    f.write("line\n")
    f.write(f"350 {i} {blips[0]} 375 {i} {blips[1]}\n")
    f.write("line\n")
    f.write(f"375 {i} {blips[1]} 400 {i} {blips[2]}\n")
    f.write("line\n")
    f.write(f"400 {i} {blips[2]} 425 {i} 0\n")

f.write("ident\n")
f.write("rotate\n")
f.write("x -40\n")
f.write("apply\n")
f.write("save\n")
f.write("gallery.png\n")

f.close()
