#!/usr/bin/perl 

use strict;
use warnings;

my @selectedletters = ('a', 'e', 'd', 'o', 'g', 'y');
my @foundwords;
my @words;
my $filename = "words_alphas.txt";
open (my $file_handle, '<', $filename) or die "Cannot open file '$filename' : $!";

my @lines = <$file_handle>;
close ($file_handle) or die "Cannot lose file '$filename': $!";

my $match = 0;
my $lineword;
foreach $lineword (@lines){#for each line in the file as it's being processed
    $match = 0;
    my $linelength = length($lineword);#get the length of the lineword selected in the above loop
    my $i;
    for($i = 0; $i < $linelength; $i++){ #length of word
        #make 2nd loop with size of selected letters array that compares the letter to whatever is the selected letter from the word
        my $j;
        my $slLength = scalar(@selectedletters);
        for($j = 0; $j < $slLength; $j++){
            my $char = substr($lineword, $i, 1); #have to use substr in perl to access elements of a string.
            if($char eq $selectedletters[$j]){
                #dostuff
            }
        }

    }
 
}

  
