package tec.ac.cr.gladiators;

import tec.ac.cr.gladiators.logic.*;

public class main {

    public static void main(String args[]){
        GladiatorsManager demo = new GladiatorsManager();

        //Initialize population
        demo.getPopulation().initializePopulation();

        //Calculate fitness of each individual
        demo.getPopulation().calculateFitness();

        System.out.println("Generation: " + demo.getGenerationCount() + " Fittest: " + demo.getPopulation().getFittestValue());


        //While population gets an individual with maximum fitness
        while (demo.getPopulation().getFittest().getFitness() < 792) {
            demo.setGenerationCount(demo.getGenerationCount() + 1);

            //Do selection
            demo.selection();

            //Do crossover
            demo.crossover();

            demo.mutation();

            //Add fittest offspring to population
            demo.addFittestOffspring();

            //Calculate new fitness value
            demo.getPopulation().calculateFitness();

            System.out.println("Generation: " + demo.getGenerationCount() + " Fittest: " + demo.getPopulation().getFittestValue());
        }

    }

}
