package tec.ac.cr.gladiators.logic;

import java.util.ArrayList;

public class Generator {


    public static ArrayList<Towers> generateTowers(int num){
        ArrayList<Towers> towersArrayList = new ArrayList<>();
        for (int i = 1; i < (num + 1); i++){
            towersArrayList.add(new Towers(i,i, i, i, i));
        }
        return towersArrayList;
    }

}
