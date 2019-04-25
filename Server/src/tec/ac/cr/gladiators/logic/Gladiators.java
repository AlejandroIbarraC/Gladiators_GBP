package tec.ac.cr.gladiators.logic;

public class Gladiators {

    public Gladiators(int identification, int ageNumber, int probability, int gensToSurvive, int emotionInteligence, int condition, int strenghtUT, int strenghtLT, int calculatedResistence){
        this.id = identification;
        this.age = ageNumber;
        this.survivalProbability = probability;
        this.howManyGensWillSurvive = gensToSurvive;
        this.emotionalInteligence = emotionInteligence;
        this.physicalCondition = condition;
        this.strenghtInUpperTrunk = strenghtUT;
        this.strenghtInLowerTrunk = strenghtLT;
        this.resistence = calculatedResistence;
    }

    public Gladiators(){}

    private int id;
    private int age;
    private int survivalProbability;
    private int howManyGensWillSurvive;
    private int emotionalInteligence;
    private int physicalCondition;
    private int strenghtInUpperTrunk;
    private int strenghtInLowerTrunk;
    private int resistence;

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public int getSurvivalProbability() {
        return survivalProbability;
    }

    public void setSurvivalProbability(int survivalProbability) {
        this.survivalProbability = survivalProbability;
    }

    public int getHowManyGensWillSurvive() {
        return howManyGensWillSurvive;
    }

    public void setHowManyGensWillSurvive(int howManyGensWillSurvive) {
        this.howManyGensWillSurvive = howManyGensWillSurvive;
    }

    public int getEmotionalInteligence() {
        return emotionalInteligence;
    }

    public void setEmotionalInteligence(int emotionalInteligence) {
        this.emotionalInteligence = emotionalInteligence;
    }

    public int getPhysicalCondition() {
        return physicalCondition;
    }

    public void setPhysicalCondition(int physicalCondition) {
        this.physicalCondition = physicalCondition;
    }

    public int getStrenghtInUpperTrunk() {
        return strenghtInUpperTrunk;
    }

    public void setStrenghtInUpperTrunk(int strenghtInUpperTrunk) {
        this.strenghtInUpperTrunk = strenghtInUpperTrunk;
    }

    public int getStrenghtInLowerTrunk() {
        return strenghtInLowerTrunk;
    }

    public void setStrenghtInLowerTrunk(int strenghtInLowerTrunk) {
        this.strenghtInLowerTrunk = strenghtInLowerTrunk;
    }

    public int getResistence() {
        return resistence;
    }

    public void setResistence(int resistence) {
        this.resistence = resistence;
    }
}
