package tec.ac.cr.gladiators.server;

import tec.ac.cr.gladiators.logic.Generator;
import tec.ac.cr.gladiators.logic.Gladiators;
import tec.ac.cr.gladiators.logic.Holder;

import javax.ws.rs.*;
import javax.ws.rs.core.MediaType;
import java.util.ArrayList;

@Path("populations/gladiators")
public class GladiatorsServer {

    @GET
    @Produces(MediaType.APPLICATION_JSON)
    public ArrayList<Gladiators> generateGladiators(){
        System.out.println(1);
        if (Holder.gladiatorsArrayList == null){
            return Generator.generateGladiators(10);
        }
        return Holder.gladiatorsArrayList;
    }

    @POST
    @Path("stats")
    @Consumes(MediaType.APPLICATION_JSON)
    public void getGladiators(ArrayList<Gladiators> gladiatorsArrayList){
        System.out.println(2);
        //Agregar lo de fitness aqui
        Holder.gladiatorsArrayList = gladiatorsArrayList;
    }

}
