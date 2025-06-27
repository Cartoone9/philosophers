<div align="center">
  <img src="https://i.ibb.co/Zzx7BpbW/Screenshot-from-2025-06-23-17-23-40.png" alt="Project score">
</div>

# philosophers
  
This is my implementation of the Dining Philosophers problem for 42 School. The goal was to manage concurrency and shared resources safely in C using threads and mutexes. Through this, I learned the fundamentals of multithreading, deadlock avoidance, and synchronization.

## Table of Contents

- [About](#philosophers)
- [The Dining Philosophers Problem](#the-dining-philosophers-problem)
- [Usage](#usage)
- [Example](#example)
- [Note on Project State](#note-on-project-state)
- [Known Issues & Fix Suggestions](#known-issues--fix-suggestions)
- [License](#license)

### The Dining Philosophers Problem

The Dining Philosophers problem is a classic concurrency scenario where several philosophers sit around a table, each needing two forks to eat: one from their left and one from their right. Since the forks are shared between neighbors, a naive implementation can lead to deadlocks (where everyone is waiting forever) or starvation (where some never get to eat). The challenge lies in coordinating access to these shared resources safely and efficiently using threads and synchronization.

## Usage

To compile the program, navigate to the project folder `philo/` and run:
```bash
make
```

Then you can use the program like this:
```bash
./philo nb_philosophers time_to_die time_to_eat time_to_sleep [max_nb_meals]
```

- nb_philosophers: Number of philosophers

- time_to_die: Time in ms before a philosopher dies without eating

- time_to_eat: Time in ms a philosopher takes to eat

- time_to_sleep: Time in ms a philosopher sleeps

- max_nb_meals (optional): If all philosophers eat this many times, simulation ends

## Example

Using the values `4`, `410`, `200`, `200`:  
<video src="https://github.com/user-attachments/assets/9daa6b96-51fd-4905-9ed4-4592b06fb5c8" controls></video>

## Note on Project State

All projects from my 42 cursus are preserved in their state immediately following their final evaluation. While they may contain mistakes or stylistic errors, I've chosen not to alter them. This approach provides a clear and authentic timeline of my progress and learning journey as a programmer.

## Known Issues & Fix Suggestions

The program has a memory leak when the value `0` is passed as `max_nb_meals`:
![Leak](https://i.ibb.co/20B0H9Cm/Screenshot-from-2025-06-23-16-26-26.png)  

One easy way to fix this is to modify the main function like this:  
```diff
 int	main(int ac, char **av)
 {
 	t_table	table;

 	if (ac == 5 || ac == 6)
 	{
 		if (ft_check_n_fill_table(av, &table) == ERROR)
 			return (ERROR);

+		if (table.max_meal == 0)
+			return (OK);

		if (ft_make_spoon(&table) == ERROR || ft_make_philo(&table) == ERROR)
		{
			ft_clean_table(&table);
			return (ERROR);
		}

-		if (table.max_meal == 0)
-			return (OK);

...
```

## License

[MIT](https://choosealicense.com/licenses/mit/)  
