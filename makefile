
#makefile Blog Part 8
CC= g++ -std=c++11
BlogPart8: BlogPart8.o Area.o Post.o  User.o Superuser.o UserList.o
		$(CC) BlogPart8.o Area.o Post.o User.o Superuser.o UserList.o -o BlogPart8

BlogPart8.o: BlogPart8.cpp
		 $(CC) -c BlogPart8.cpp

Area.o: Area.h Area.cpp
		 $(CC) -c Area.h
		 $(CC) -c Area.cpp

Post.o: Post.h Post.cpp
		 $(CC) -c Post.h
		 $(CC) -c Post.cpp

User.o: User.h User.cpp
		 $(CC) -c User.h
		 $(CC) -c User.cpp

Superuser.o: Superuser.h Superuser.cpp
		 $(CC) -c Superuser.h
		 $(CC) -c Superuser.cpp

UserList.o: UserList.h UserList.cpp
		 $(CC) -c UserList.h
		 $(CC) -c UserList.cpp
clean:
		rm -rf *.o  *.gch  BlogPart8
