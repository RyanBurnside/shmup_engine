#There are some REALLY bad things going on here, use .o files not .h for depends

OBJS = main.o Engine.o Render_Core.o Ship.o Emitter.o Actor.o Path.o Image_Data.o Bullet.o

ShmupFramework: $(OBJS)
	g++ -Wall -o ShmupFramework $(OBJS) -lSDL

main.o: main.cpp Engine.h Engine.h
	g++ -Wall -c main.cpp

Engine.o: Engine.cpp Engine.h
	g++ -Wall -c Engine.cpp

Image_Data.o: Image_Data.cpp Image_Data.h
	g++ -Wall -c Image_Data.cpp


Actor.o: Actor.cpp Actor.h
	g++ -Wall -c Actor.cpp

Render_Core.o: Render_Core.cpp Render_Core.h
	g++ -Wall -c Render_Core.cpp 

Ship.o: Ship.cpp Ship.h Actor.h Path.h Emitter.h
	g++ -Wall -c Ship.cpp

Emitter.o: Emitter.cpp Emitter.h Bullet.h
	g++ -Wall -c Emitter.cpp

Bullet.o: Bullet.cpp Bullet.h Actor.h  
	g++ -Wall -c Bullet.cpp 

Path.o: Path.cpp Path.h
	g++ -Wall -c Path.cpp

clean:
	rm $(OBJS)


