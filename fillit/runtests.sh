# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    runtests.sh                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mberglun <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/11 17:18:52 by mberglun          #+#    #+#              #
#    Updated: 2019/12/11 19:54:37 by mberglun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Test error files
testvalid()
{
	path=$1
	expected=$2
	echo ">>$path"
	i=0;
	errors=0
	for file in $path/*
	do
		res="$(./valid.test "$file")"
		if [[ ! "$res" = "$expected" ]]
		then
			echo "\033[0;31mTestfile $file failed\033[0m"
			echo "$(cat -e "$file")"
			errors=$[$errors+1]
		fi

		i=$[$i+1]
	done
}

testvalid ./testfiles/errors "error"
testvalid ./testfiles/valids "valid"

