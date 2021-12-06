# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    template.mk                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agautier <agautier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/29 14:49:12 by agautier          #+#    #+#              #
#    Updated: 2021/11/05 16:10:24 by agautier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef TEMPLATE_MK
	TEMPLATE_MK = 1

S		=	
I		=	./
O		=	obj/
D		=	dep/


OBJ			=	$(SRC:$S%.cpp=$O%.o)
DEP			=	$(SRC:$S%.cpp=$D%.d)

CXX			=	c++

CXXFLAGS	+=	-I$I
CXXFLAGS	+=	-Wall -Wextra -Werror -std=c++98 -pedantic-errors

RM			=	/bin/rm -f
RMDIR		=	/bin/rm -Rf

.PHONY: all clean fclean re

all: $(NAME)

$O:
	@mkdir -p $@

$(OBJ): | $O

$(OBJ): $O%.o: $S%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$D:
	@mkdir -p $@

$(DEP): | $D

$(DEP): $D%.d: $S%.cpp
	$(CXX) $(CXXFLAGS) -MM -MF $@ -MT "$O$*.o $@" $<

$(NAME): $(OBJ)
	$(CXX) $(LDFLAGS) $^ -o $@

clean:
	$(RMDIR) $(wildcard $(NAME).dSYM)
	$(RMDIR) $O
	$(RM) $(wildcard $(DEP))
	$(RMDIR) $D

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE)

-include $(DEP)

endif
