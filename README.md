<div align="center">
  <img src="https://i.ibb.co/Zzx7BpbW/Screenshot-from-2025-06-23-17-23-40.png" alt="Project score">
</div>

# philosophers
  
Here you'll find my Philosophers project, an assignment from 42 School. The main goal was to solve the dining philosophers problem, which meant learning to control how different parts of a program access the same things at once. This experience was vital for understanding multithreading, how to avoid common problems like deadlocks, and working with shared resources in C programming.

## Usage

To compile the program, navigate to the project folder `philo/` and run:
```bash
make
```

Then you can use the program like this:
```bash
./philo nb_philosophers time_to_die time_to_eat time_to_sleep [max_nb_meals]
```

## Examples

Using the values `4`, `410`, `200`, `200`:  
<video src="https://github.com/user-attachments/assets/9daa6b96-51fd-4905-9ed4-4592b06fb5c8" controls></video>

## Note on Project State

All projects from my 42 cursus are preserved in their state immediately following their final evaluation. While they may contain mistakes or stylistic errors, I've chosen not to alter them. This approach provides a clear and authentic timeline of my progress and learning journey as a programmer.

## Known Issues & Fix Suggestions

The program has a memory leak when the value `0` is passed as `max_nb_meals`:
![Leak](https://i.ibb.co/20B0H9Cm/Screenshot-from-2025-06-23-16-26-26.png)  

One easy way to fix this is to modify the main function:  
```C
int	main(int ac, char **av)
{
	t_table	table;

	if (ac == 5 || ac == 6)
	{
		if (ft_check_n_fill_table(av, &table) == ERROR)
			return (ERROR);
		if (ft_make_spoon(&table) == ERROR || ft_make_philo(&table) == ERROR)
		{
			ft_clean_table(&table);
			return (ERROR);
        	}

        	// MOVE UP THE FOLLOWING IF CHECK
		if (table.max_meal == 0)
			return (OK);

...
```

Like so:  
```C
int	main(int ac, char **av)
{
	t_table	table;

	if (ac == 5 || ac == 6)
	{
		if (ft_check_n_fill_table(av, &table) == ERROR)
			return (ERROR);

        	// EDIT BEGIN
		if (table.max_meal == 0)
			return (OK);
        	//EDIT END

		if (ft_make_spoon(&table) == ERROR || ft_make_philo(&table) == ERROR)
		{
			ft_clean_table(&table);
			return (ERROR);
        }

...
```

## License

[MIT](https://choosealicense.com/licenses/mit/)  
