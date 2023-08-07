
#makefile Blog Part 8
CC= g++ -std=c++11
BlogPart8: BlogPart8.o Area.o Post.o  User.o Superuser.o UserList.o
		$(CC) BlogPart8.o Area.o Post.o User.o Superuser.o UserList.o -o BlogPart8

BlogPart8.o: BlogPart8.cpp
		 $(CC) -c BlogPart8.cpp

Area.o: Area.cpp
		 $(CC) -c Area.cpp

Post.o: Post.cpp
		 $(CC) -c Post.cpp

User.o: User.cpp
		 $(CC) -c User.cpp

Superuser.o: Superuser.cpp
		 $(CC) -c Superuser.cpp

UserList.o: UserList.cpp
		 $(CC) -c UserList.cpp
clean:
		rm -rf *.o  *.gch  BlogPart8
