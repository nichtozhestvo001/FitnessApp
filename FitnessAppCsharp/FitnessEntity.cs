public abstract class FitnessEntity
{
    protected string Id { get; init; }
    protected static int TotalEntities = 0;

    protected FitnessEntity(string id)
    {
        Id = id;
        TotalEntities++;
    }

    public abstract string GetInfo();
    public abstract FitnessEntity Clone();

    public static int GetTotalEntities() => TotalEntities;
}
