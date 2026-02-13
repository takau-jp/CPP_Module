# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/06 23:25:43 by stanaka2          #+#    #+#              #
#    Updated: 2026/02/13 19:40:54 by stanaka2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

echo "TEST: ./megaphone \"shhhhh... I think the students are asleep...\""
./megaphone "shhhhh... I think the students are asleep..."

echo "

=================================================

"

echo "TEST: ./megaphone Damnit \" ! \" \"Sorry students, I thought this thing was off.\""
./megaphone Damnit " ! " "Sorry students, I thought this thing was off."

echo "

=================================================

"

echo "TEST: ./megaphone"
./megaphone

echo "

=================================================

"

echo "TEST: ./megaphone hello"
./megaphone hello

echo "

=================================================

"

echo "TEST: ./megaphone HELLO"
./megaphone HELLO

echo "

=================================================

"

echo "TEST: ./megaphone \"hello world\""
./megaphone "hello world"

echo "

=================================================

"

echo "TEST: ./megaphone hello world"
./megaphone hello world

echo "

=================================================

"

echo "TEST: ./megaphone hello world test"
./megaphone hello world test

echo "

=================================================

"

echo "TEST: ./megaphone \"hello\" \"world\" \"test\""
./megaphone "hello" "world" "test"

echo "

=================================================

"

echo "TEST: ./megaphone \"\""
./megaphone ""

echo "

=================================================

"

echo "TEST: ./megaphone \"hello\" \"\" \"world\""
./megaphone "hello" "" "world"

echo "

=================================================

"

echo "TEST: ./megaphone \"\" \"a\" \"\""
./megaphone "" "a" ""

echo "

=================================================

"

echo "TEST: ./megaphone a"
./megaphone a

echo "

=================================================

"

echo "TEST: ./megaphone A"
./megaphone A

echo "

=================================================

"

echo "TEST: ./megaphone abcdefghijklmnopqrstuvwxyz"
./megaphone abcdefghijklmnopqrstuvwxyz

echo "

=================================================

"

echo "TEST: ./megaphone ABCDEFGHIJKLMNOPQRSTUVWXYZ"
./megaphone ABCDEFGHIJKLMNOPQRSTUVWXYZ

echo "

=================================================

"

echo "TEST: ./megaphone \"HeLLo WoRLd\""
./megaphone "HeLLo WoRLd"

echo "

=================================================

"

echo "TEST: ./megaphone 123456789"
./megaphone 123456789

echo "

=================================================

"

echo "TEST: ./megaphone \"!@#\$%^&*()\""
./megaphone "!@#\$%^&*()"

echo "

=================================================

"

echo "TEST: ./megaphone \"test123!@#\""
./megaphone "test123!@#"

echo "

=================================================

"

echo "TEST: ./megaphone \"hello123WORLD\""
./megaphone "hello123WORLD"

echo "

=================================================

"

echo "TEST: ./megaphone \"   hello\""
./megaphone "   hello"

echo "

=================================================

"

echo "TEST: ./megaphone \"hello   \""
./megaphone "hello   "

echo "

=================================================

"

echo "TEST: ./megaphone \"hello     world\""
./megaphone "hello     world"

echo "

=================================================

"

echo "TEST: ./megaphone \" \""
./megaphone " "

echo "

=================================================

"

echo "TEST: ./megaphone \"     \""
./megaphone "     "

echo "

=================================================

"

echo "TEST: ./megaphone \"this is a test.\""
./megaphone "this is a test."

echo "

=================================================

"

echo "TEST: ./megaphone \"What time is it?\""
./megaphone "What time is it?"

echo "

=================================================

"

echo "TEST: ./megaphone \"WATCH OUT!\""
./megaphone "WATCH OUT!"

echo "

=================================================

"

echo "TEST: ./megaphone a b c d e"
./megaphone a b c d e

echo "

=================================================

"

echo "TEST: ./megaphone one two three four five"
./megaphone one two three four five

echo "

=================================================

"

echo "TEST: ./megaphone \"a\" \"b\" \"c\" \"d\" \"e\""
./megaphone "a" "b" "c" "d" "e"

echo "

=================================================

"

echo "TEST: ./megaphone \"café\""
./megaphone "café"

echo "

=================================================

"

echo "TEST: ./megaphone \"naïve résumé\""
./megaphone "naïve résumé"

echo "

=================================================

"

echo "TEST: ./megaphone \"hello\\nworld\""
./megaphone "hello\nworld"

echo "

=================================================

"

echo "TEST: ./megaphone \"hello\\tworld\""
./megaphone "hello\tworld"

echo "

=================================================

"

echo "TEST: ./megaphone \"user@example.com\""
./megaphone "user@example.com"

echo "

=================================================

"

echo "TEST: ./megaphone \"https://example.com\""
./megaphone "https://example.com"

echo "

=================================================

"

echo "TEST: ./megaphone \"C++ is fun\""
./megaphone "C++ is fun"

echo "

=================================================

"

echo "TEST: ./megaphone \"42 is the answer\""
./megaphone "42 is the answer"

echo "

=================================================

"
