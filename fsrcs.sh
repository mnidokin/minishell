#! /bin/sh
find src -type f -name \*.c > fsrcs
echo "libft/includes/libft.h" > fhdr
find inc -type f -name \*.h >> fhdr
find src -type d > fdirs
echo "libft/includes" > fhdir
find inc -type d >> fhdir
# sed -i -e 's/srcs/obj/g' fdirs
# rm fdirs-e 2>&-
# find libft -type f -name \*.c > fsrcs
# cd libft
# find src -type f -name \*.c > fsrcs
# find ft_printf -type f -name \*.c >> fsrcs
# echo "libft/libft.h" > fhdr
# find includes -type f -name \*.h > fhdr

# cd ft_printf
# find . -type f -name \*.c -maxdepth 1 > fsrcs
# cd ..find srcs -type d > fdirs; sed -i -e s/srcs/obj/g fdirs