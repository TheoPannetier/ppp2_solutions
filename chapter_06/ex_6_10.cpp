// Exercise 6.10

// # Analysis
// The program must:
// - ask for two numbers a and b, which must be strictly positive integers
// - ask for permutation or combination, no other option
// - compute the corresponding number
// - return the result
// - case a = 0: what if there are 0 possible numbers? not legal
// - case b = 0: what if the sequence is of length 0? not legal
// - case a < b: illegal bc we'd have to compute the factorial of a neg int, which is undefined.
// "A permutation is an ordered *subset* of a set" so I suppose it means we cannot use the same number twice, so a must be more than b
// - case a = b: is ok, if 0! = 1. C(a,b) evaluates to 1, as it should.
//
// # Design
// Define get_factorial(int x) {
//   int fct = 1;
//   for (int i = x; x > 0; --i)
//      fct *= i;
//  return fct
// }
// Define get_nb_perms(a,b)
// {
//   return get_fact(a) / get_fact(a-b);
// }
// Define get_nb_comb(a,b)
// {
//   return get_nb_perms(a,b) / get_fact(b);
// }
// Data input
//  ask for and store a and b;
//  if a or b not int or not a and b > 0
//      error: "a and b must be strictly positive integers"
//  if a < b
//      error: "a must be greater or equal to b"
//  ask for and store p_or_c
//  if p_or_c not 'p' or 'c'
//      error: "only enter 'p' for permutation or 'c' for combination"
// Computation
// if (p_or_c == p)
//   return get_perm(a,b)
// else
//   return get_comb(a,b)
// EOP
//----------------------------------------------------------------------------