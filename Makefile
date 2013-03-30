#There are some REALLY bad things going on here, use .o files not .h for depends

OBJS = main.o Engine.o Render_Core.o Ship.o Emitter.o Actor.o Path.o Image_Data.o Bullet.o

ShmupFramework: $(OBJS)
	g++ -o ShmupFramework $(OBJS) -lSDL

main.o: main.cpp Engine.h Engine.h
	g++ -c main.cpp

Engine.o: Engine.cpp Engine.h
	g++ -c Engine.cpp

Image_Data.o: Image_Data.cpp Image_Data.h
	g++ -c Image_Data.cpp


Actor.o: Actor.cpp Actor.h
	g++ -c Actor.cpp

Render_Core.o: Render_Core.cpp Render_Core.h
	g++ -c Render_Core.cpp 

Ship.o: Ship.cpp Ship.h Actor.h Path.h Emitter.h
	g++ -c Ship.cpp

Emitter.o: Emitter.cpp Emitter.h Bullet.h
	g++ -c Emitter.cpp

Bullet.o: Bullet.cpp Bullet.h Actor.h  
	g++ -c Bullet.cpp 

Path.o: Path.cpp Path.h
	g++ -c Path.cpp

clean:
	rm $(OBJS)
