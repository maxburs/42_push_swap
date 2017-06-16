# push_swap

## description

Given two stacks and 11 predefined operations sort numbers given on the standard imput in as few operations as possible.

## usage

Compile with make

```
./push_swap [integer, ...], ["integer, ..."]

./test.sh [integer count] [max operations] [optional: number of tests]

echo $operations | checker [integer, ...], ["integer, ..."]
```

## example

```
$> ./push_swap 10 5 200 -4
pb
rra
rra
pa
rra
rra
```

```
$> args='10 5 200 -4'; ./push_swap $args | ./checker $args
OK
```

```
$> ./test.sh 500 5000 10
4999
5074
5003
4941
4982
4917
4971
4994
4924
5283
7/10
```

## operations

* sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
* sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
* ss : sa and sb at the same time.
* pa : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
* pb : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
* ra : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
* rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
* rr : ra and rb at the same time.
* rra : reverse rotate a - shift down all elements of stack a by 1. The flast element becomes the first one.
* rrb : reverse rotate b - shift down all elements of stack b by 1. The flast element becomes the first one.
* rrr : rra and rrb at the same time.