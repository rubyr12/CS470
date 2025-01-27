# Ruby Rosales

# Create main directory
maindir=$(date +%Y-%m-%d_%H:%M:%S)
mkdir $maindir

# Array that holds names of programming languages
uniquelanguages=("Java" "Python" "C" "C++" "Ruby" "C#" "JavaScript" "Swift" "Assembly" "R")

# Loop to create 10 subdirectories and files
for i in {1..10}; do

    # Format subdirectory and text file name
    if [ $i -lt 10 ]; then
        subname="file10$i"
        textname="tuser50$i.txt"
    else
        subname="file1$i"
        textname="tuser5$i.txt"
    fi

    # Create subdirectory within main directory
    mkdir $maindir/$subname

    # Write the name of a programming language to a text file within each subdirectory
    echo ${uniquelanguages[i - 1]} > $maindir/$subname/$textname
done

