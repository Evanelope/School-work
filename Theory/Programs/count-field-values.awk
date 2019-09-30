#!/usr/bin/awk -f
#Evan Meyerhoff
#CS311
#Lab 2 awk program
#Prints out words starting with capital letters first.
#Syntax: count-field-values.awk FIELDS_LIST [CSV_FILE...]
BEGIN 	{
	print "\n\n"
	FS = ","
    	if (ARGV[1] ~ "[[:digit:],?]*") split(ARGV[1], a, ",")
    	delete ARGV[1]	#takes ARGV[1] and splits into array a. It's then removed from ARGV.
}

FNR > 1 {for (i in a) myarray[$a[i]]++} #makes associative array; increasing value for each repeated value.

END{
	PROCINFO["sorted_in"] = "@ind_str_asc" #for in loop processed in alphabetical order uppercase first.
	for (var in myarray) print var "\t" myarray[var]
	print "\n\n"
}
