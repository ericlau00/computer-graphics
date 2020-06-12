robot: main.py matrix.py mdl.py display.py draw.py gmath.py
	python3 main.py scripts/robot.mdl

box: main.py matrix.py mdl.py display.py draw.py gmath.py
	python3 main.py scripts/box.mdl

face: main.py matrix.py mdl.py display.py draw.py gmath.py
	python3 main.py scripts/face.mdl

animate: main.py matrix.py mdl.py display.py draw.py gmath.py
	python3 main.py scripts/simple_anim.mdl

sphere: main.py matrix.py mdl.py display.py draw.py gmath.py
	python3 main.py scripts/sphere.mdl

clean:
	rm *pyc *out parsetab.py

clear:
	rm *pyc *out parsetab.py *ppm
