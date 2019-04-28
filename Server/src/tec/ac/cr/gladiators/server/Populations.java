package tec.ac.cr.gladiators.server;

import tec.ac.cr.gladiators.logic.Holder;

import javax.ws.rs.POST;
import javax.ws.rs.Path;

@Path("populations")
public class Populations {

    @POST
    public void initialize(){
        System.out.println("5");
        Holder.gladiatorsArrayList = null;
        Holder.towersArrayList = null;
    }

}
