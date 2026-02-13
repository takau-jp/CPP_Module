# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/12 22:57:05 by stanaka2          #+#    #+#              #
#    Updated: 2026/02/12 23:25:54 by stanaka2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

echo "TEST: cat tests/input01.txt | ./my_awesome_phonebook"
cat tests/input01.txt | ./my_awesome_phonebook

echo "

=================================================

"

echo "TEST: cat tests/input02.txt | ./my_awesome_phonebook"
cat tests/input02.txt | ./my_awesome_phonebook

echo "

=================================================

"

echo "TEST: cat tests/input03.txt | ./my_awesome_phonebook"
cat tests/input03.txt | ./my_awesome_phonebook

echo "

=================================================

"

echo "TEST: cat tests/input04.txt | ./my_awesome_phonebook"
cat tests/input04.txt | ./my_awesome_phonebook
