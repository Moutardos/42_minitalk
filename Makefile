CC = cc
ODIR = obj
BDIR = bin
SERVER = $(BDIR)/server
CLIENT = $(BDIR)/client
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
_OBJS_SERV = server.o utils.o
OBJS_SERV = $(patsubst %,$(ODIR)/%,$(_OBJS_SERV))
_OBJS_CLIENT = client.o
OBJS_CLIENT = $(patsubst %,$(ODIR)/%,$(_OBJS_CLIENT))

all: $(LIBFT) $(CLIENT) $(SERVER)

$(ODIR) :
	mkdir -p $@

$(BDIR) :
	mkdir -p $@

$(ODIR)/%.o : src/%.c | $(ODIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C libft

$(SERVER): $(OBJS_SERV) | $(BDIR)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)

$(CLIENT): $(OBJS_CLIENT) | $(BDIR)
	$(CC) $(CFLAGS) -o $@ $< $(LIBFT)


clean:
	$(RM) -R $(ODIR)
	$(MAKE) -C libft $@

fclean: clean
	$(MAKE) -C libft $@
	$(RM) -R $(BDIR)

re: fclean all

.PHONY: all clean fclean re 
