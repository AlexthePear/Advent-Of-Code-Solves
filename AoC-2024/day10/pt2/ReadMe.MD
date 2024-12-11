# pt2
It ups the blink count from 25 to 75

the optimization for this is actually really cool
the order doesnt actually matter since you are just spliting the num into two or changing its value
you can split multiple of the same number at the same time
lets say you have mutliple 20s about a 100
well you can see that if you split the 20s
you will get 2 and 0s
how many of each
exactly a 100
so best space optimization is to do a hash_map to store the num and the counts
same thing goes for any of the other options;


then for better time efficiency you can memo cache transformation
if you are splitting the num by digits that is technically O(n) but if you already encountered the num before you can just store it in memo
saving time on the transform calculation not needed but runs way faster with it.