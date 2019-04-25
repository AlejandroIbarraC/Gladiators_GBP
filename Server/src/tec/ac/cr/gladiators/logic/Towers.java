package tec.ac.cr.gladiators.logic;

public class Towers {

    public Towers(int typeOfTheAmmo, int damageOfTheAmmo, int rangeOfTheAmmo){
        this.typeOfAmmo = typeOfTheAmmo;
        this.damageOutput = damageOfTheAmmo;
        this.range = rangeOfTheAmmo;
    }

    public Towers(){}

    private int typeOfAmmo;
    private int damageOutput;
    private int range;

    public int getTypeOfAmmo() {
        return typeOfAmmo;
    }

    public void setTypeOfAmmo(int typeOfAmmo) {
        this.typeOfAmmo = typeOfAmmo;
    }

    public int getDamageOutput() {
        return damageOutput;
    }

    public void setDamageOutput(int damageOutput) {
        this.damageOutput = damageOutput;
    }

    public int getRange() {
        return range;
    }

    public void setRange(int range) {
        this.range = range;
    }
}
