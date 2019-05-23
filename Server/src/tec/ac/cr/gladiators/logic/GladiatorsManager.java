package tec.ac.cr.gladiators.logic;

import java.util.Random;

public class GladiatorsManager {
    private Population population = new Population();
    private Gladiators fittest;
    private Gladiators secondFittest;
    private int generationCount = 0;

    /**
     *Select the two best Gladiators of all the population
     */
    public void selection() {

        //Select the most fittest individual
        fittest = population.getFittest();

        //Select the second most fittest individual
        secondFittest = population.getSecondFittest();
    }

    /**
     * Make a children between the best Gladiators
     */
    public void crossover() {
        Random rn = new Random();
        int[] genes = new int[8];
        //Select a random crossover point
        int crossOverPoint = rn.nextInt(population.getIndividuals()[0].getGenes().length);

        //Swap values among parents
        for (int i = 0; i < crossOverPoint; i++) {
            int temp = fittest.getGenes()[i];
            genes[i] = temp;
        }
        for(int i = crossOverPoint; i<8; i++){
            int temp = secondFittest.getGenes()[i];
            genes[i] = temp;
        }
        Gladiators child = new Gladiators.Builder().setAge(genes[0]).
                setEmotionalInteligence(genes[1]).
                setHowManyGensWillSurvive(genes[2]).
                setHowManyGensWillSurvive(genes[3]).
                setPhysicalCondition(genes[3]).
                setStrenghtInLowerTrunk(genes[4]).
                setStrenghtInUpperTrunk(genes[5]).
                setSurvivalProbability(genes[7]).build();
        child.fillGenes();
        child.calcFitness();
        child.calcResistance();
        int index = population.getLeastFittestIndex();
        population.getIndividuals()[index] = child;
    }

    /**
     * Search the best gladiator of the population
     * @return Gladiator
     */
    public Gladiators getFittestOffspring() {
        if (fittest.getFitness() > secondFittest.getFitness()) {
            return fittest;
        }
        return secondFittest;
    }


    /**
     * Replace least fittest individual from most fittest
     */
    public void addFittestOffspring() {

        //Update fitness values of offspring
        fittest.calcFitness();
        secondFittest.calcFitness();

        //Get index of least fit individual
        int leastFittestIndex = population.getLeastFittestIndex();
        Gladiators best = getFittestOffspring();
        Gladiators replace = new Gladiators.Builder().setAge(best.getAge()).
                setEmotionalInteligence(best.getEmotionalInteligence()).
                setHowManyGensWillSurvive(best.getHowManyGensWillSurvive()).
                setHowManyGensWillSurvive(best.getHowManyGensWillSurvive()).
                setPhysicalCondition(best.getPhysicalCondition()).
                setStrenghtInLowerTrunk(best.getStrenghtInLowerTrunk()).
                setStrenghtInUpperTrunk(best.getStrenghtInUpperTrunk()).
                setSurvivalProbability(best.getSurvivalProbability()).build();
                replace.calcResistance();
                replace.fillGenes();
                replace.calcFitness();

        //Replace least fittest individual from most fittest offspring
        population.getIndividuals()[leastFittestIndex] = replace;
    }

    /**
     * Try to mutate a random gladiator with a 20% of chance
     */
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

    /**
     * Fixes the ids of the gladiators
     */
    public void updateId(){
        int length = population.getIndividuals().length;
        for (int i = 0; i < length; i++){
            population.getIndividuals()[i].setId(i);
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
