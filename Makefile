OBJS = main.o Engine.o Render_Core.o Ship.o Emitter.o Actor.o Path.o Image_Data.o

ShmupFramework: $(OBJS)
	g++ -o ShmupFramework $(OBJS) -lSDL

main.o: main.cpp Engine.h Engine.h
	g++ -c main.cpp

Engine.o: Engine.cpp Engine.h
	g++ -c Engine.cpp

Image_data.o: Image_Data.cpp Image_data.h
	g++ -c Image_Data.cpp

Render_Core.o: Render_Core.cpp Render_Core.h
	g++ -c Render_Core.cpp 

Ship.o: Ship.cpp Ship.h Actor.h Path.h 
	g++ -c Ship.cpp

Emitter.o: Emitter.cpp Emitter.h
	g++ -c Emitter.cpp

Actor.o: Actor.cpp Actor.h
	g++ -c Actor.cpp

Path.o: Path.cpp Path.h
	g++ -c Path.cpp

clean:
	rm $(OBJS)
