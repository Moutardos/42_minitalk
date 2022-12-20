CC = cc
SERVER = server
CLIENT = client
ODIR = obj
BDIR = bin
RM = rm -f
CFLAGS = -Wall -Wextra
LIBFT = libft.a
_OBJS_SERV = server.o
OBJS_SERV = $(patsubst %,$(ODIR)/%,$(_OBJS_SERV))
_OBJS_CLIENT = client.o
OBJS_CLIENT = $(patsubst %,$(ODIR)/%,$(_OBJS_CLIENT))

all: $(LIBFT) $(CLIENT) $(SERVER)

$(ODIR)/%.o : src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C libft
	mkdir -p $(ODIR)
	mkdir -p $(BDIR)

$(SERVER): $(OBJS_SERV)
	$(CC) $(CFLAGS) -o $(BDIR)/$@ $< libft/$(LIBFT)

$(CLIENT): $(OBJS_CLIENT)
	$(CC) $(CFLAGS) -o $(BDIR)/$@ $< libft/$(LIBFT)


clean:
	$(RM) -R $(ODIR)
	$(MAKE) -C libft $@

fclean: clean
	$(MAKE) -C libft $@
	$(RM) -R $(BDIR)

re: fclean all

