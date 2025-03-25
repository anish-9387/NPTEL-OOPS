import java.util.HashMap;

public class ConfigurationManagerUsingSingletonPattern{
    private static ConfigurationManagerUsingSingletonPattern instance;

    private HashMap<String, String> config;

    private ConfigurationManagerUsingSingletonPattern(){
        config=new HashMap<>();
    }

    public static ConfigurationManagerUsingSingletonPattern getInstance(){
        if(instance==null){
            instance=new ConfigurationManagerUsingSingletonPattern();
        }
        return instance;
    }

    public void setConfig(String key, String value){
        config.put(key, value);
    }

    public String getConfig(String key){
        return config.get(key);
    }

    public static void main(String[] args){
        ConfigurationManagerUsingSingletonPattern configManager=ConfigurationManagerUsingSingletonPattern.getInstance();
        configManager.setConfig("appName", "SingletonApp");
        System.out.println("App name: "+configManager.getConfig("appName"));
    }
}