package tec.ac.cr.gladiators.logic;

import java.util.Random;

public class GladiatorsManager {
    private Population population = new Population();
    private Gladiators fittest;
    private Gladiators secondFittest;
    private int generationCount = 0;

    //Selection
    public void selection() {

        //Select the most fittest individual
        fittest = population.getFittest();

        //Select the second most fittest individual
        secondFittest = population.getSecondFittest();
    }

    //Crossover
    public void crossover() {
        Random rn = new Random();

        //Select a random crossover point
        int crossOverPoint = rn.nextInt(population.getIndividuals()[0].getGenes().length);

        //Swap values among parents
        for (int i = 0; i < crossOverPoint; i++) {
            int temp = fittest.getGenes()[i];
            fittest.getGenes()[i] = secondFittest.getGenes()[i];
            secondFittest.getGenes()[i] = temp;

        }
    }

    //Get fittest offspring
    public Gladiators getFittestOffspring() {
        if (fittest.getFitness() > secondFittest.getFitness()) {
            return fittest;
        }
        return secondFittest;
    }


    //Replace least fittest individual from most fittest offspring
    public void addFittestOffspring() {

        //Update fitness values of offspring
        fittest.calcFitness();
        secondFittest.calcFitness();

        //Get index of least fit individual
        int leastFittestIndex = population.getLeastFittestIndex();

        //Replace least fittest individual from most fittest offspring
        population.getIndividuals()[leastFittestIndex] = getFittestOffspring();
    }

    //Mutation
    public void mutation() {
        Random rn = new Random();

        if (rn.nextInt(100)<= 20){
            System.out.println("A mutation has occurred to Gladiator: " + this);
            //Select a random mutation point
            int mutationPoint = rn.nextInt(population.getIndividuals()[0].getGenes().length);

            int mutationValue = rn.nextInt(100);

            while (fittest.getGenes()[mutationPoint] > mutationValue ){
                mutationValue = rn.nextInt(100);
            }
            fittest.getGenes()[mutationPoint] = mutationValue;

            mutationPoint = rn.nextInt(population.getIndividuals()[0].getGenes().length);

            while (secondFittest.getGenes()[mutationPoint] > mutationValue ){
                mutationValue = rn.nextInt(100);
            }
            secondFittest.getGenes()[mutationPoint] = mutationValue;

        }
    }


    public Population getPopulation() {
        return population;
    }

    public void setPopulation(Population population) {
        this.population = population;
    }

    public Gladiators getFittest() {
        return fittest;
    }

    public void setFittest(Gladiators fittest) {
        this.fittest = fittest;
    }

    public Gladiators getSecondFittest() {
        return secondFittest;
    }

    public void setSecondFittest(Gladiators secondFittest) {
        this.secondFittest = secondFittest;
    }

    public int getGenerationCount() {
        return generationCount;
    }

    public void setGenerationCount(int generationCount) {
        this.generationCount = generationCount;
    }
}
